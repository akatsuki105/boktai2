	push {r4, r5, r6, r7, lr}
	adds r3, r1, #0
	mov ip, r2
	adds r1, #0x78
	movs r4, #0
	ldrsh r2, [r1, r4]
	ldr r1, [r3, #0x14]
	subs r6, r2, r1
	adds r5, r2, r1
	ldr r7, _08053D98 @ =0x000008DC
	adds r1, r0, r7
	movs r2, #0
	movs r4, #1
_08053D5E:
	ldrh r0, [r1, #6]
	ands r0, r4
	cmp r0, #0
	beq _08053D9C
	ldrb r0, [r1, #3]
	ldrb r7, [r3, #8]
	cmp r0, r7
	bne _08053D9C
	adds r0, r1, #0
	adds r0, #0x58
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	blt _08053D9C
	cmp r0, r5
	bgt _08053D9C
	mov r0, ip
	cmp r0, #0
	bne _08053D86
	strb r4, [r1, #1]
_08053D86:
	ldr r0, [r1, #8]
	cmp r0, #1
	beq _08053D94
	cmp r0, #1
	blo _08053D94
	cmp r0, #2
	bne _08053D9C
_08053D94:
	movs r0, #1
	b _08053DA6
	.align 2, 0
_08053D98: .4byte 0x000008DC
_08053D9C:
	adds r2, #1
	adds r1, #0x78
	cmp r2, #0x1f
	ble _08053D5E
	movs r0, #0
_08053DA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
