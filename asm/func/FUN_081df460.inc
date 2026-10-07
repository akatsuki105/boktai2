	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF48C
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF484
	movs r1, #0
	bl VM_ExecByID
_081DF484:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
_081DF48C:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF4A4
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF534
_081DF4A4:
	movs r7, #0
	movs r5, #0
	ldrh r6, [r4, #0x1a]
	movs r1, #0x29
	adds r1, r1, r4
	mov r8, r1
	cmp r7, r6
	bge _081DF4FC
	movs r2, #0xf0
	lsls r2, r2, #6
	mov ip, r2
_081DF4BA:
	cmp r5, #0
	bge _081DF4C8
	ldr r1, _081DF4C4 @ =0x0000FFFF
	b _081DF4D0
	.align 2, 0
_081DF4C4: .4byte 0x0000FFFF
_081DF4C8:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF4D0:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF4E6
	movs r1, #1
	b _081DF4E8
_081DF4E6:
	movs r1, #0
_081DF4E8:
	cmp r1, #0
	beq _081DF4F6
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #1
	bne _081DF4F6
	adds r7, #1
_081DF4F6:
	adds r5, #1
	cmp r5, r6
	blt _081DF4BA
_081DF4FC:
	cmp r7, r6
	bne _081DF50A
	ldr r2, _081DF528 @ =FUN_081df540
	adds r0, r4, #0
	movs r1, #0x16
	bl Entity9A9F_SetState
_081DF50A:
	mov r2, r8
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DF534
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r2]
	cmp r1, #0x3b
	bls _081DF530
	ldr r2, _081DF52C @ =0x00001001
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	b _081DF534
	.align 2, 0
_081DF528: .4byte FUN_081df540
_081DF52C: .4byte 0x00001001
_081DF530:
	adds r1, #1
	strb r1, [r2]
_081DF534:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
