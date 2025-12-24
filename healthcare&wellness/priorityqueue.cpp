import heapq

patients = [(5, 'Patient1'), (10, 'Patient2'), (2, 'Patient3')] # Higher number = higher urgency
heapq._heapify_max(patients)

while patients:
    urgency, name = heapq._heappop_max(patients)
    print(name, urgency)

