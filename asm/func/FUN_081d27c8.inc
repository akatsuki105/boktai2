	push {r4, lr}
	ldr r4, _081D27E4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D27E8
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	bne _081D2804
	b _081D27F2
	.align 2, 0
_081D27E4: .4byte 0x03002BE0
_081D27E8:
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	beq _081D2804
_081D27F2:
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D2804
	movs r0, #1
	b _081D2806
_081D2804:
	movs r0, #0
_081D2806:
	pop {r4}
	pop {r1}
	bx r1
