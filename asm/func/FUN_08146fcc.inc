	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08146FE4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146FE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146FEA
	.align 2, 0
_08146FE4: .4byte 0x0000046D
_08146FE8:
	movs r0, #0
_08146FEA:
	cmp r0, #0
	beq _0814700C
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efb60
	movs r1, #0x97
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _08147024 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0814700C:
	ldr r1, _08147028 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814701E
	ldr r0, _0814702C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814701E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08147024: .4byte 0x0000FFFB
_08147028: .4byte 0x0000046E
_0814702C: .4byte 0x0000046B
