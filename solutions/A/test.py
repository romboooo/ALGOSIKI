import subprocess
import unittest

class TestSolution(unittest.TestCase):
    @staticmethod
    def _run_task0(input_data):
        process = subprocess.run(
            ["/Users/rom4ikk/Desktop/учеба/2_курс/2_сем/алгосы/solutions/Amateur-agronomist"],
            input=input_data,
            capture_output=True,
            check=True,
            text=True  # Указываем, что ввод и вывод должны быть текстовыми
        )
        return process.stdout

    def test_example_basic(self):
        # Пример из условия задачи
        self.assertEqual(self._run_task0("65 6 6 6 23 9"), "3 6")

    def test_example_with_initial_triplet(self):
        # Пример, где тройное повторение начинается с начала
        self.assertEqual(self._run_task0("66 6 6 6 23 9"), "3 6")

    def test_all_unique_flowers(self):
        # Все цветы различны, вся последовательность валидна
        self.assertEqual(self._run_task0("51 2 3 4 5"), "1 5")

    def test_two_flowers_same(self):
        # Минимальное количество элементов, два одинаковых цветка
        self.assertEqual(self._run_task0("21 1"), "1 2")

    def test_single_flower(self):
        # Минимальное количество элементов, один цветок
        self.assertEqual(self._run_task0("11"), "1 1")

    def test_single_flower_duplicate(self):
        # Повтор теста с одним цветком
        self.assertEqual(self._run_task0("11"), "1 1")

    def test_all_same_flowers(self):
        # Все цветы одинаковы: допустим только отрезок длины 2
        self.assertEqual(self._run_task0("51 1 1 1 1"), "1 2")

    def test_no_triplets_in_long_sequence(self):
        # Нет троек подряд, вся последовательность валидна
        self.assertEqual(self._run_task0("101 1 2 2 3 3 2 2 1 1"), "1 10")

    def test_all_same_flowers_long(self):
        # Ещё один тест, когда все элементы одинаковы (длинная последовательность)
        self.assertEqual(self._run_task0("82 2 2 2 2 2 2 2"), "1 2")

    def test_complex_repeating_pattern(self):
        # Сложный случай с повторениями, где длиннейший валидный отрезок начинается не с первого элемента
        self.assertEqual(self._run_task0("91 2 2 2 1 1 2 2 2"), "3 8")

    def test_pattern_with_triplets_in_middle(self):
        # Тест, где тройное повторение встречается в середине: лучший отрезок выбирается между индексами 2 и 7
        self.assertEqual(self._run_task0("101 1 1 2 2 3 3 3 4 4"), "2 7")

    def test_alternating_pattern(self):
        # Чередующаяся последовательность, где нет ни одного повтора более двух
        self.assertEqual(self._run_task0("101 2 1 2 1 2 1 2 1 2"), "1 10")

    def test_large_input_alternating(self):
        # Большой тест: n = 200000, чередование 1 и 2 гарантирует отсутствие троек подряд
        n = 200000
        numbers = ["1" if i % 2 == 0 else "2" for i in range(n)]
        input_str = f"{n}{' '.join(numbers)}"
        expected = f"1 {n}"
        self.assertEqual(self._run_task0(input_str), expected)

if __name__ == '__main__':
    unittest.main()