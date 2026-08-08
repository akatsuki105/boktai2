	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08066DCE
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_08066d2c
	cmp r0, #0
	beq _08066DCE
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _08066DB2
	cmp r0, #5
	bne _08066DC6
_08066DB2:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08066DC6
	adds r0, r4, #0
	bl FUN_08066c64
	b _08066DE0
_08066DC6:
	adds r0, r4, #0
	bl FUN_08066abc
	b _08066DE0
_08066DCE:
	ldr r1, _08066DF0 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08066DE0
	adds r0, r4, #0
	bl FUN_08066d10
_08066DE0:
	ldr r0, _08066DF4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066DF0: .4byte 0x000003CE
_08066DF4: .4byte 0x000003D1
