	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp]
	mov r8, r3
	ldr r7, [sp, #0x24]
	ldr r0, [sp, #0x28]
	cmp r0, #8
	bhi _08019654
	lsls r0, r0, #2
	ldr r1, _080195BC @ =_080195C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080195BC: .4byte _080195C0
_080195C0: @ jump table
	.4byte _08019654 @ case 0
	.4byte _080195E4 @ case 1
	.4byte _08019654 @ case 2
	.4byte _080195F4 @ case 3
	.4byte _08019604 @ case 4
	.4byte _08019614 @ case 5
	.4byte _08019624 @ case 6
	.4byte _08019634 @ case 7
	.4byte _08019644 @ case 8
_080195E4:
	ldr r0, _080195F0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0
	b _0801965E
	.align 2, 0
_080195F0: .4byte 0x00001C1E
_080195F4:
	ldr r0, _08019600 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #4
	b _0801965E
	.align 2, 0
_08019600: .4byte 0x00001C1E
_08019604:
	ldr r0, _08019610 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #6
	b _0801965E
	.align 2, 0
_08019610: .4byte 0x00001C1E
_08019614:
	ldr r0, _08019620 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #8
	b _0801965E
	.align 2, 0
_08019620: .4byte 0x00001C1E
_08019624:
	ldr r0, _08019630 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xa
	b _0801965E
	.align 2, 0
_08019630: .4byte 0x00001C1E
_08019634:
	ldr r0, _08019640 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xc
	b _0801965E
	.align 2, 0
_08019640: .4byte 0x00001C1E
_08019644:
	ldr r0, _08019650 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xe
	b _0801965E
	.align 2, 0
_08019650: .4byte 0x00001C1E
_08019654:
	ldr r0, _08019694 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #2
_0801965E:
	strh r0, [r6, #0x26]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r5, r6, #0
	adds r5, #0x2c
	ldrh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08019690
	cmp r1, #0
	blt _08019690
	ldr r0, _08019698 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08019690
	ldr r0, _0801969C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080196A0
_08019690:
	movs r4, #0
	b _080196AE
	.align 2, 0
_08019694: .4byte 0x00001C1E
_08019698: .4byte 0x030046A8
_0801969C: .4byte 0x030046AC
_080196A0:
	ldr r0, _080196C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080196AE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080196C4
	adds r0, #4
	b _080196D0
	.align 2, 0
_080196C0: .4byte 0x030046A4
_080196C4:
	ldr r0, _080196E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080196D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080196E8
	cmp r2, #2
	beq _080196EC
	b _080196F0
	.align 2, 0
_080196E4: .4byte 0x030046A4
_080196E8:
	ldrb r0, [r5, #4]
	b _080196EE
_080196EC:
	ldrb r0, [r5]
_080196EE:
	subs r1, r1, r0
_080196F0:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _080196FA
	strh r1, [r6, #0x2e]
_080196FA:
	movs r0, #0
	str r0, [r6, #0x18]
	mov r3, r8
	str r3, [r6, #0x1c]
	movs r0, #0x14
	strh r0, [r6, #0x20]
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r6, #0x22]
	cmp r7, #7
	ble _08019712
	movs r7, #8
_08019712:
	strh r7, [r6, #0x24]
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r1, _080197A0 @ =gSineTable
	mov sl, r1
	adds r5, r7, #0
_08019724:
	adds r4, r7, #0
	adds r4, #8
	mov r2, sb
	strb r2, [r5]
	ldr r2, _080197A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080197A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080197AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x20
	strb r0, [r5, #1]
	mov r0, sb
	strh r0, [r5, #2]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #4]
	mov r2, r8
	lsls r0, r2, #2
	strh r0, [r5, #6]
	ldr r1, [r6, #0x28]
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	adds r0, r4, #0
	bl Particle_SetPose
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	ldrb r2, [r5, #1]
	ldrh r3, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197B0
	asrs r0, r0, #0xc
	b _080197B6
	.align 2, 0
_080197A0: .4byte gSineTable
_080197A4: .4byte 0x030046B8
_080197A8: .4byte 0x000003FF
_080197AC: .4byte 0x0203B400
_080197B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080197B6:
	strh r0, [r5, #0x20]
	mov r0, sb
	strh r0, [r5, #0x22]
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197CE
	asrs r2, r0, #0xc
	b _080197D4
_080197CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080197D4:
	strh r2, [r5, #0x24]
	ldrh r1, [r5, #2]
	ldrh r3, [r5, #0x22]
	adds r1, r1, r3
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r0, r0, r3
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0x2e]
	adds r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x30]
	adds r0, r2, r0
	strh r0, [r5, #0x24]
	movs r0, #1
	strb r0, [r5, #0x17]
	add r8, r0
	adds r5, #0x30
	adds r7, #0x30
	mov r0, r8
	cmp r0, #7
	ble _08019724
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
