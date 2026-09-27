	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D31A2
	movs r0, #1
	b _081D31A4
_081D31A2:
	movs r0, #0
_081D31A4:
	cmp r0, #0
	beq _081D31E0
	movs r6, #0
	movs r0, #0xb4
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r5, r7, r1
_081D31B6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r4, r0, r6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D31CE
	adds r0, r5, #0
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4]
_081D31CE:
	adds r5, #0x10
	adds r6, #1
	cmp r6, #3
	ble _081D31B6
	ldr r0, _081D31EC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D31E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D31EC: .4byte 0xFFFFF7FF
