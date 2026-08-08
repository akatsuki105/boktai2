	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov sb, r0
	cmp r0, #0
	beq _082356F2
	ldrb r0, [r0]
	cmp r0, #0
	bne _082356FC
_082356F2:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _0823584A
_082356FC:
	mov r0, sb
	bl FUN_08234f6c
	mov r8, r0
	cmp r0, #0
	bne _08235712
	mov r2, r8
	strh r2, [r6]
	strh r2, [r6, #2]
	strh r2, [r6, #4]
	b _0823584A
_08235712:
	ldr r2, _0823579C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082357A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _082357A4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	ldrb r1, [r2]
	bl Mod
	mov sl, r0
	mov r4, sp
	mov r0, sp
	mov r1, r8
	movs r2, #0
	bl FUN_08234f80
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
	mov r4, sl
	mov r3, sb
	ldrb r1, [r3]
	adds r0, r4, r1
	cmp r4, r0
	bge _082357C6
	mov r5, sp
_08235754:
	adds r0, r4, #0
	bl Mod
	adds r7, r0, #0
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	mov r1, r8
	bl FUN_08234f80
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r2, [sp, #8]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _082357A8
	ldr r2, [sp, #0xc]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _082357A8
	movs r0, #4
	ldrsh r1, [r5, r0]
	ldr r2, [sp, #8]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _082357A8
	ldr r2, [sp, #0xc]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _082357A8
	movs r0, #1
	b _082357AA
	.align 2, 0
_0823579C: .4byte 0x030046B8
_082357A0: .4byte 0x000003FF
_082357A4: .4byte 0x0203B400
_082357A8:
	movs r0, #0
_082357AA:
	cmp r0, #0
	beq _082357B8
	str r7, [sp, #0x10]
	ldrh r0, [r5]
	strh r0, [r6]
	ldrh r0, [r5, #4]
	strh r0, [r6, #4]
_082357B8:
	adds r4, #1
	mov r0, sb
	ldrb r1, [r0]
	mov r2, sl
	adds r0, r2, r1
	cmp r4, r0
	blt _08235754
_082357C6:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082357EA
	cmp r1, #0
	blt _082357EA
	ldr r0, _082357F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082357EA
	ldr r0, _082357F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082357F8
_082357EA:
	movs r4, #0
	b _08235806
	.align 2, 0
_082357F0: .4byte 0x030046A8
_082357F4: .4byte 0x030046AC
_082357F8:
	ldr r0, _08235818 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235806:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823581C
	adds r0, #4
	b _08235828
	.align 2, 0
_08235818: .4byte 0x030046A4
_0823581C:
	ldr r0, _0823583C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235828:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235840
	cmp r2, #2
	beq _08235844
	b _08235848
	.align 2, 0
_0823583C: .4byte 0x030046A4
_08235840:
	ldrb r0, [r6, #4]
	b _08235846
_08235844:
	ldrb r0, [r6]
_08235846:
	subs r1, r1, r0
_08235848:
	strh r1, [r6, #2]
_0823584A:
	ldr r0, [sp, #0x10]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
