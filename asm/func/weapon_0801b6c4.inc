	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldr r6, _0801B70C @ =0x08DA9E8C
	movs r4, #0
	movs r5, #0
	adds r2, r6, #0
	subs r2, #0x24
	movs r1, #0x41
_0801B6D6:
	ldrb r0, [r2, #1]
	cmp r0, r3
	bne _0801B6F2
	ldrb r0, [r2, #2]
	cmp r0, #4
	beq _0801B6F2
	ldrb r0, [r2, #3]
	cmp r0, r7
	bgt _0801B6F2
	cmp r0, r4
	blt _0801B6F2
	adds r6, r2, #0
	adds r4, r0, #0
	movs r5, #1
_0801B6F2:
	adds r2, #0x24
	subs r1, #1
	cmp r1, #0
	bge _0801B6D6
	cmp r5, #0
	bne _0801B728
	cmp r3, #1
	beq _0801B710
	cmp r3, #1
	ble _0801B720
	cmp r3, #2
	beq _0801B718
	b _0801B720
	.align 2, 0
_0801B70C: .4byte 0x08DA9E8C
_0801B710:
	ldr r0, _0801B714 @ =0x08DAA1C8
	b _0801B72A
	.align 2, 0
_0801B714: .4byte 0x08DAA1C8
_0801B718:
	ldr r0, _0801B71C @ =0x08DAA474
	b _0801B72A
	.align 2, 0
_0801B71C: .4byte 0x08DAA474
_0801B720:
	ldr r0, _0801B724 @ =0x08DA9F1C
	b _0801B72A
	.align 2, 0
_0801B724: .4byte 0x08DA9F1C
_0801B728:
	adds r0, r6, #0
_0801B72A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
