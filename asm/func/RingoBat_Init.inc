	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sl, r1
	movs r1, #0
	mov r0, sl
	strb r1, [r0, #1]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	strh r1, [r2, #4]
	strb r1, [r2, #6]
	movs r4, #0x84
	lsls r4, r4, #1
	add r4, sl
	ldr r1, _0805BB08 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _0805BB0C @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, _0805BB10 @ =0x00001688
	add r0, r8
	str r0, [r4, #0xc]
	mov r5, sl
	adds r5, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _0805BB14 @ =0x05000002
	bl CpuSet
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	mov r7, sl
	adds r7, #0x7c
	ldr r2, _0805BB18 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	ldr r1, _0805BB1C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805BB20 @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	mov r6, sl
	adds r6, #0x14
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB24 @ =RingoBat_OnHurt
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x22]
	adds r0, r7, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	movs r0, #0x20
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	movs r1, #0x20
	strh r1, [r5, #4]
	movs r2, #0
	strh r2, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	ldr r2, _0805BB28 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB2C @ =RingoBat_OnHit
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x20]
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BB08: .4byte 0x0000DA6D
_0805BB0C: .4byte 0x00000263
_0805BB10: .4byte 0x00001688
_0805BB14: .4byte 0x05000002
_0805BB18: .4byte 0xFFFF0000
_0805BB1C: .4byte 0x0000FFFF
_0805BB20: .4byte 0x00004005
_0805BB24: .4byte RingoBat_OnHurt
_0805BB28: .4byte 0x00002001
_0805BB2C: .4byte RingoBat_OnHit
