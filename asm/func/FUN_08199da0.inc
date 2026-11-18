	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r0, #1
	subs r1, #0x47
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199DD2
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08199DD4
_08199DD2:
	movs r0, #0
_08199DD4:
	cmp r0, #0
	beq _08199DFE
	adds r3, r4, #0
	adds r3, #0x4e
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r3, #0x50
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _08199ED4 @ =0x00000125
	adds r1, r4, r2
	movs r0, #0x14
	strb r0, [r1]
_08199DFE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r1, [r5]
	adds r0, r1, #1
	strb r0, [r5]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08199E48
	ldr r0, [r4, #0xc]
	ldr r2, _08199ED8 @ =0x00000CC6
	adds r1, r6, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	movs r1, #5
	movs r0, #0x8b
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08199EDC @ =0x00000117
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	ldr r1, _08199EE0 @ =0x00000111
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08199E48:
	ldrb r0, [r5]
	movs r5, #7
	ands r5, r0
	cmp r5, #0
	bne _08199ECA
	ldr r0, [r4, #0x6c]
	ldr r1, [r4, #0x70]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08199EE4 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x64
	lsls r1, r1, #0x10
	ldr r4, _08199EE8 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	adds r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r1, #0x50
	orrs r0, r1
	ands r0, r4
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	str r5, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r3, #0
	bl EmitSmoke
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08199ECA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08199ED4: .4byte 0x00000125
_08199ED8: .4byte 0x00000CC6
_08199EDC: .4byte 0x00000117
_08199EE0: .4byte 0x00000111
_08199EE4: .4byte 0xFFFF0000
_08199EE8: .4byte 0x0000FFFF
