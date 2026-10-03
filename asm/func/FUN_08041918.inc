	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r0, _080419C0 @ =0x030044E0
	ldrh r0, [r0, #2]
	movs r1, #1
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	movs r6, #0x87
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	cmp r0, #0
	beq _080419CC
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080419CC
	movs r6, #0xe0
	lsls r6, r6, #2
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080419CC
	ldr r2, _080419C4 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804197A
	ldr r6, _080419C8 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080419CC
_0804197A:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _0804198E
	cmp r0, #7
	beq _0804198E
	movs r1, #0
_0804198E:
	cmp r1, #0
	beq _080419CC
	movs r6, #0x87
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r2, #0
	mov r8, r2
	cmp r0, #0
	beq _080419D0
	movs r6, #1
	mov r8, r6
	cmp r0, #1
	beq _080419D0
	movs r1, #3
	mov r8, r1
	cmp r0, #5
	bne _080419D0
	movs r2, #2
	mov r8, r2
	b _080419D0
	.align 2, 0
_080419C0: .4byte 0x030044E0
_080419C4: .4byte 0x00000446
_080419C8: .4byte 0x00000442
_080419CC:
	movs r6, #3
	mov r8, r6
_080419D0:
	movs r5, #0
	bl FUN_0823d5f0
	cmp r0, #0
	beq _08041A3E
	ldr r0, _08041A78 @ =0x000F4240
	str r0, [sp, #0x20]
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041A3E
	movs r1, #0x80
	lsls r1, r1, #4
	mov sb, r1
	ldr r2, _08041A7C @ =0x00000434
	adds r2, r2, r7
	mov ip, r2
_080419F0:
	ldrh r0, [r4, #0xe]
	mov r6, sb
	ands r0, r6
	cmp r0, #0
	beq _08041A32
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _08041A32
	adds r3, r4, #0
	adds r3, #0x64
	mov r0, ip
	ldr r1, [r0]
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r6, #4
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r1, [sp, #0x20]
	cmp r2, r1
	bge _08041A32
	str r2, [sp, #0x20]
	adds r5, r4, #0
_08041A32:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r4, [r0]
	cmp r4, #0
	bne _080419F0
_08041A3E:
	cmp r5, #0
	beq _08041AA4
	mov r6, sl
	cmp r6, #0
	bne _08041AA4
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041ACC
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	mov r2, r8
	adds r6, r0, r2
_08041A58:
	cmp r4, r5
	bne _08041A80
	ldrb r0, [r5, #0xa]
	cmp r0, #0
	bne _08041A96
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #1
	strb r0, [r5, #0xa]
	b _08041A96
	.align 2, 0
_08041A78: .4byte 0x000F4240
_08041A7C: .4byte 0x00000434
_08041A80:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _08041A96
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #0
	strb r0, [r4, #0xa]
_08041A96:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _08041A58
	b _08041ACC
_08041AA4:
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041ACC
_08041AAA:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _08041AC0
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #0
	strb r0, [r4, #0xa]
_08041AC0:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r4, [r0]
	cmp r4, #0
	bne _08041AAA
_08041ACC:
	cmp r5, #0
	beq _08041B16
	mov r6, sl
	cmp r6, #0
	beq _08041B16
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r0, #0x66
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x68
	movs r6, #0
	ldrsh r0, [r0, r6]
	str r0, [sp, #0xc]
	adds r3, r5, #0
	adds r3, #0x44
	add r2, sp, #0x10
	movs r1, #3
_08041B04:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08041B04
	ldr r0, [r5, #0x40]
	movs r1, #0
	bl VM_ExecByID
_08041B16:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
