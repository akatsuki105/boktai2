	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #8]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _08235594
	ldrb r0, [r0]
	cmp r0, #0
	bne _082355A0
_08235594:
	movs r0, #0
	strh r0, [r7]
	strh r0, [r7, #2]
	strh r0, [r7, #4]
	subs r0, #1
	b _082356B4
_082355A0:
	ldr r2, _0823563C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08235640 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08235644 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ldrb r1, [r2]
	bl Mod
	adds r6, r0, #0
	adds r5, r6, #0
	mov r3, r8
	ldrb r1, [r3]
	adds r0, r6, r1
	cmp r6, r0
	bge _082356B2
	mov r4, sp
_082355CC:
	adds r0, r5, #0
	bl Mod
	str r0, [sp, #0xc]
	mov r0, sl
	lsls r1, r0, #0x18
	ldr r3, [sp, #0xc]
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	lsrs r1, r1, #0x18
	bl FUN_08234f90
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r2, r2, r0
	mov r0, sb
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r3, [sp, #8]
	cmp r0, r3
	blo _082356A6
	ldrh r0, [r4]
	strh r0, [r7]
	ldrh r1, [r4, #4]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08235638
	cmp r1, #0
	blt _08235638
	ldr r0, _08235648 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235638
	ldr r0, _0823564C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235650
_08235638:
	movs r4, #0
	b _0823565E
	.align 2, 0
_0823563C: .4byte 0x030046B8
_08235640: .4byte 0x000003FF
_08235644: .4byte 0x0203B400
_08235648: .4byte 0x030046A8
_0823564C: .4byte 0x030046AC
_08235650:
	ldr r0, _08235670 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823565E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235674
	adds r0, #4
	b _08235680
	.align 2, 0
_08235670: .4byte 0x030046A4
_08235674:
	ldr r0, _08235694 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235680:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235698
	cmp r2, #2
	beq _0823569C
	b _082356A0
	.align 2, 0
_08235694: .4byte 0x030046A4
_08235698:
	ldrb r0, [r7, #4]
	b _0823569E
_0823569C:
	ldrb r0, [r7]
_0823569E:
	subs r1, r1, r0
_082356A0:
	strh r1, [r7, #2]
	ldr r0, [sp, #0xc]
	b _082356B4
_082356A6:
	adds r5, #1
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, r1
	cmp r5, r0
	blt _082355CC
_082356B2:
	adds r0, r6, #0
_082356B4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
