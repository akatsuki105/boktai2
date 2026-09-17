	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x92
	lsls r1, r1, #4
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x20
_081EB27A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EB28A
	movs r0, #1
	b _081EB28C
_081EB28A:
	movs r0, #0
_081EB28C:
	cmp r0, #0
	beq _081EB296
	adds r0, r4, #0
	bl FUN_0822dabc
_081EB296:
	adds r4, #0x48
	adds r5, #1
	cmp r5, #0x1f
	ble _081EB27A
	movs r1, #0
	ldr r0, _081EB2AC @ =0x030001C4
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EB2AC: .4byte 0x030001C4
