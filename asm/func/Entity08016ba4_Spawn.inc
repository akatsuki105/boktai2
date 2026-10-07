	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _0801672C @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _080166D6
	movs r0, #0
	movs r1, #0
	bl Entity08016ba4_Create
	cmp r0, #0
	bne _080166D6
	b _08016862
_080166D6:
	movs r2, #0
	ldr r3, _0801672C @ =0x03000064
	movs r1, #0x24
_080166DC:
	ldr r0, [r3]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _080166E8
	b _08016854
_080166E8:
	movs r0, #1
	strb r0, [r5]
	strb r4, [r5, #1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080166FA
	movs r0, #8
	strb r0, [r5, #1]
_080166FA:
	movs r0, #0
	mov sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	blt _08016706
	b _08016846
_08016706:
	ldr r6, _08016730 @ =0x030046B8
	ldr r2, _08016734 @ =0x000003FF
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r5
	mov r8, r3
	adds r7, r5, #0
	adds r7, #0x10
	adds r4, r5, #4
_08016718:
	movs r0, #1
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _08016738
	mov r1, sp
	ldrb r1, [r1, #8]
	strb r1, [r4, #1]
	b _08016756
	.align 2, 0
_0801672C: .4byte 0x03000064
_08016730: .4byte 0x030046B8
_08016734: .4byte 0x000003FF
_08016738:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08016764 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r1, [sp, #8]
	adds r0, r1, r0
	strb r0, [r4, #1]
_08016756:
	ldr r2, [sp, #0x34]
	cmp r2, #0
	bne _08016768
	mov r3, sp
	ldrh r3, [r3, #0x30]
	strh r3, [r4, #2]
	b _08016786
	.align 2, 0
_08016764: .4byte 0x0203B400
_08016768:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08016790 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	ldr r3, [sp, #0x30]
	adds r0, r3, r0
	strh r0, [r4, #2]
_08016786:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	bne _08016794
	ldr r2, [sp, #0x38]
	b _080167B0
	.align 2, 0
_08016790: .4byte 0x0203B400
_08016794:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080167DC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x3c]
	bl Mod
	ldr r3, [sp, #0x38]
	adds r2, r3, r0
_080167B0:
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080167E0 @ =0x085B0A08
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ands r2, r1
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _080167E4
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r4, #6]
	b _08016802
	.align 2, 0
_080167DC: .4byte 0x0203B400
_080167E0: .4byte 0x085B0A08
_080167E4:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _0801684C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	strh r0, [r4, #6]
_08016802:
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	adds r0, r7, #0
	movs r1, #0
	bl Particle_AddToDrawList
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
	ldr r0, _08016850 @ =0x03000064
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r3, #0x44
	add r8, r3
	adds r7, #0x44
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	bge _08016846
	b _08016718
_08016846:
	movs r0, #0
	b _08016866
	.align 2, 0
_0801684C: .4byte 0x0203B400
_08016850: .4byte 0x03000064
_08016854:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #5
	bgt _08016862
	b _080166DC
_08016862:
	movs r0, #1
	rsbs r0, r0, #0
_08016866:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
