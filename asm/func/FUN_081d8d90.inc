	push {lr}
	movs r2, #0xed
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _081D8DA6
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	b _081D8DBA
_081D8DA6:
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	bl Time_GetSpanOfTime
	cmp r0, #2
	bgt _081D8DB8
	movs r0, #0
	b _081D8DBA
_081D8DB8:
	movs r0, #1
_081D8DBA:
	pop {r1}
	bx r1
	.align 2, 0
