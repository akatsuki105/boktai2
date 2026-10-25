	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r5, sb
	movs r0, #0x48
	add r0, sb
	mov sl, r0
	ldr r0, _08029698 @ =0x00000899
	add r0, sb
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r2, _0802969C @ =0x00000868
	add r2, sb
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r7, r0, #0
	movs r0, #0x40
	rsbs r0, r0, #0
	ands r7, r0
	mov r3, sp
	movs r4, #0xc0
	lsls r4, r4, #2
	ldr r2, _080296A0 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080296A4
	asrs r1, r0, #0xc
	b _080296AA
	.align 2, 0
_08029698: .4byte 0x00000899
_0802969C: .4byte 0x00000868
_080296A0: .4byte gSineTable
_080296A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080296AA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080296C8 @ =gSineTable
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080296CC
	asrs r0, r0, #0xc
	b _080296D2
	.align 2, 0
_080296C8: .4byte gSineTable
_080296CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080296D2:
	strh r0, [r3, #4]
	ldr r0, _08029780 @ =0x00000899
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r3, r3, r5
	mov r8, r3
	add r0, r8
	ldr r2, [r0]
	mov r6, sp
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldr r5, _08029784 @ =0x00000868
	add r5, sb
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r2, sl
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #0xc
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sp
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r5, r3]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r4, r4, r0
	mov r5, r8
	cmp r4, #0
	bge _08029756
	rsbs r4, r4, #0
_08029756:
	cmp r4, #0x1f
	bgt _0802975C
	adds r7, #0x40
_0802975C:
	ldr r3, _08029788 @ =0x0000084C
	add r3, sb
	movs r4, #0xc0
	lsls r4, r4, #2
	ldr r2, _0802978C @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08029790
	asrs r1, r0, #0xc
	b _08029796
	.align 2, 0
_08029780: .4byte 0x00000899
_08029784: .4byte 0x00000868
_08029788: .4byte 0x0000084C
_0802978C: .4byte gSineTable
_08029790:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08029796:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080297B2
	asrs r0, r0, #0xc
	b _080297B8
_080297B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080297B8:
	strh r0, [r3, #4]
	ldr r0, _080297F4 @ =0x00000899
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r5, r0
	ldr r2, [r0]
	ldr r1, _080297F8 @ =0x0000084C
	add r1, sb
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080297F4: .4byte 0x00000899
_080297F8: .4byte 0x0000084C
