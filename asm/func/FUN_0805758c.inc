	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r7, r1, #0
	mov sb, r2
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r7, #8]
	cmp r0, #0
	beq _080575EE
	movs r0, #0
	strb r0, [r7, #8]
	ldr r6, _08057624 @ =0x0203B400
	ldr r4, _08057628 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0805762C @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #3
	mov r5, sb
	ands r2, r5
	lsls r2, r2, #3
	add r2, r8
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	movs r5, #0
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	strb r5, [r7, #0x10]
_080575EE:
	mov r6, r8
	ldr r1, [r6, #0x18]
	movs r3, #0
	ldrb r2, [r7, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r7, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057606
	movs r3, #1
_08057606:
	movs r0, #0
	cmp r2, #1
	bls _0805760E
	movs r0, #1
_0805760E:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08057630
	subs r0, #1
	strb r0, [r7, #0xe]
	b _08057666
	.align 2, 0
_08057624: .4byte 0x0203B400
_08057628: .4byte 0x030046B8
_0805762C: .4byte 0x000003FF
_08057630:
	ldr r1, [r7, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057666
	ldrb r0, [r7, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057648
	subs r0, #1
	strb r0, [r7, #0xf]
	b _08057666
_08057648:
	movs r0, #0x1e
	strb r0, [r7, #0xf]
	movs r0, #0x78
	strb r0, [r7, #0xe]
	movs r1, #5
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _0805765C
	movs r1, #8
_0805765C:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r2, [r7, #0x14]
	b _08057992
_08057666:
	ldrb r3, [r7, #0x10]
	cmp r3, #0
	bne _08057694
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r7, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _0805767A
	movs r2, #1
_0805767A:
	cmp r2, #0
	beq _08057694
	movs r1, #4
	mov r5, r8
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805768A
	movs r1, #8
_0805768A:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r3, [r7, #0x14]
	b _08057992
_08057694:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _080576B4
	ldr r2, _080576B0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _080576B6
	.align 2, 0
_080576B0: .4byte 0x085AB9A4
_080576B4:
	movs r0, #0
_080576B6:
	movs r4, #0
	strb r0, [r7, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080576C2
	b _0805798C
_080576C2:
	adds r2, r7, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r7, r5]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _080576E2
	rsbs r0, r3, #0
_080576E2:
	cmp r0, #0x17
	bgt _0805771E
	adds r0, r1, #0
	cmp r1, #0
	bge _080576EE
	rsbs r0, r1, #0
_080576EE:
	cmp r0, #0x17
	bgt _08057710
	strb r4, [r7, #6]
	movs r0, #0xff
	strb r0, [r7, #0xb]
	movs r3, #1
	mov r0, r8
	ldr r1, [r0, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r7, #4]
	strb r3, [r7, #8]
	str r4, [r7, #0x14]
	b _08057992
_08057710:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r7, #0xb]
	b _08057774
_0805771E:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057726
	rsbs r0, r1, #0
_08057726:
	cmp r0, #0x17
	bgt _0805773E
	movs r2, #1
	cmp r3, #0
	bge _08057732
	movs r2, #3
_08057732:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r7, #0xb]
	b _0805777A
_0805773E:
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	ldrb r4, [r7, #0xb]
	cmp r0, #0
	blt _0805774E
	movs r0, #1
	ands r0, r4
	b _08057754
_0805774E:
	movs r0, #1
	mov r2, sb
	ands r0, r2
_08057754:
	cmp r0, #0
	bne _0805776A
	movs r2, #1
	cmp r3, #0
	bge _08057760
	movs r2, #3
_08057760:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _0805777A
_0805776A:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057774:
	cmp r3, #0
	bge _0805777A
	movs r5, #3
_0805777A:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057790
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057790
	movs r5, #0xb
	ldrsb r5, [r7, r5]
_08057790:
	str r7, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r3, [r7, #6]
	mov sb, r3
	adds r6, r7, #0
	adds r6, #0x20
	str r6, [sp, #0x14]
_080577A0:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _080577D8 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r6, r8
	ands r0, r6
	cmp r0, #0
	bne _080577EC
	cmp r6, #0
	bne _080577DC
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _080577E0
	.align 2, 0
_080577D8: .4byte 0xFFFF0000
_080577DC:
	ldrh r0, [r4, #4]
	add r0, sb
_080577E0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _0805780C
_080577EC:
	mov r6, r8
	cmp r6, #1
	bne _080577FA
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057802
_080577FA:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057802:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_0805780C:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057834
	cmp r1, #0
	blt _08057834
	ldr r0, _08057838 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057834
	ldr r0, _0805783C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057840
_08057834:
	movs r4, #0
	b _0805784E
	.align 2, 0
_08057838: .4byte 0x030046A8
_0805783C: .4byte 0x030046AC
_08057840:
	ldr r0, _08057860 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805784E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057864
	adds r0, #4
	b _08057870
	.align 2, 0
_08057860: .4byte 0x030046A4
_08057864:
	ldr r0, _080578A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057870:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805790C
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080578A2
	cmp r1, #0
	blt _080578A2
	ldr r0, _080578AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080578A2
	ldr r0, _080578B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080578B4
_080578A2:
	movs r4, #0
	b _080578C2
	.align 2, 0
_080578A8: .4byte 0x030046A4
_080578AC: .4byte 0x030046A8
_080578B0: .4byte 0x030046AC
_080578B4:
	ldr r0, _080578D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080578C2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080578D8
	adds r0, #4
	b _080578E4
	.align 2, 0
_080578D4: .4byte 0x030046A4
_080578D8:
	ldr r0, _080578F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080578E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080578FC
	cmp r2, #2
	beq _08057900
	b _08057904
	.align 2, 0
_080578F8: .4byte 0x030046A4
_080578FC:
	ldrb r0, [r6, #4]
	b _08057902
_08057900:
	ldrb r0, [r6]
_08057902:
	subs r1, r1, r0
_08057904:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057922
_0805790C:
	mov r3, sl
	cmp r3, #0
	blt _0805791C
	mov r8, sl
	movs r6, #1
	rsbs r6, r6, #0
	mov sl, r6
	b _080577A0
_0805791C:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057924
_08057922:
	mov r2, r8
_08057924:
	cmp r2, r5
	bne _0805792C
	strb r2, [r7, #0xb]
	b _08057930
_0805792C:
	movs r0, #0xff
	strb r0, [r7, #0xb]
_08057930:
	cmp r2, #0
	bge _08057938
	movs r2, #0
	strb r2, [r7, #6]
_08057938:
	strb r2, [r7, #5]
	movs r3, #0
	ldrb r1, [r7, #5]
	ldrb r0, [r7, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057964
	cmp r1, #1
	bgt _08057952
	cmp r1, #0
	beq _0805795C
	b _08057978
_08057952:
	cmp r1, #2
	beq _0805796A
	cmp r1, #3
	beq _08057970
	b _08057978
_0805795C:
	strh r3, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057978
_08057964:
	strh r0, [r7, #0x20]
	strh r3, [r2, #4]
	b _08057978
_0805796A:
	strh r3, [r7, #0x20]
	strh r0, [r2, #4]
	b _08057978
_08057970:
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057978:
	ldrh r0, [r7, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r7, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_0805798C:
	ldr r0, [r7, #0x14]
	adds r0, #1
	str r0, [r7, #0x14]
_08057992:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
