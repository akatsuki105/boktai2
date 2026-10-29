	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r0, _080C418C @ =0x000023D4
	adds r0, r0, r2
	mov sb, r0
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _080C412E
	b _080C4246
_080C412E:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C4190 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	movs r3, #0
	ldr r0, _080C4194 @ =0x000023DC
	adds r4, r2, r0
	ldr r1, _080C4198 @ =0x000023EC
	adds r1, r1, r2
	mov r8, r1
	movs r2, #7
	mov sl, r2
_080C415A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4230
	mov r7, r8
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080C416C
	rsbs r0, r0, #0
_080C416C:
	cmp r0, #0x3f
	bgt _080C419C
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _080C417A
	rsbs r0, r0, #0
_080C417A:
	cmp r0, #0x3f
	bgt _080C419C
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #0
	strb r0, [r4]
	b _080C4230
	.align 2, 0
_080C418C: .4byte 0x000023D4
_080C4190: .4byte 0xFFFF0000
_080C4194: .4byte 0x000023DC
_080C4198: .4byte 0x000023EC
_080C419C:
	movs r3, #8
	ldrsh r0, [r4, r3]
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r2, r0, #0
	ldrh r1, [r4, #6]
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _080C41C8 @ =gSineTable
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41CC
	asrs r1, r0, #0xc
	b _080C41D2
	.align 2, 0
_080C41C8: .4byte gSineTable
_080C41CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41D2:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r4, #8]
	ldrh r1, [r4, #6]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _080C41F4 @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41F8
	asrs r1, r0, #0xc
	b _080C41FE
	.align 2, 0
_080C41F4: .4byte gSineTable
_080C41F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41FE:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	adds r0, r6, #0
	ldrh r2, [r4, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	movs r3, #0xff
	ands r0, r3
	cmp r0, #4
	bne _080C422E
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r7, #0
	movs r2, #3
	bl Particle_SetPose
_080C422E:
	movs r3, #1
_080C4230:
	adds r4, #0x38
	movs r1, #0x38
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _080C415A
	mov r1, sb
	strb r3, [r1, #3]
_080C4246:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
