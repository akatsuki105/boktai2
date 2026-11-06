	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r1
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	movs r0, #1
	strb r0, [r1, #3]
	movs r0, #0
	str r0, [r1, #4]
	mov r4, sl
	adds r4, #0xf0
	ldr r1, _0805DF70 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _0805DF74 @ =0x00000263
	bl Video_SetAuxSpritePltt
	mov r5, sl
	adds r5, #0xc4
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	movs r1, #0xe0
	add r1, sl
	mov sb, r1
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805DF78 @ =0x05000002
	bl CpuSet
	movs r4, #0x86
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	mov r7, sl
	adds r7, #0x64
	ldr r2, _0805DF7C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	mov r8, r1
	orrs r0, r1
	ldr r1, _0805DF80 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	mov r1, r8
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805DF84 @ =0x00005005
	movs r6, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805DF88 @ =Entity0805e67c_OnHurt
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	mov r0, r8
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	mov r1, r8
	strh r1, [r5, #4]
	movs r0, #0
	strh r0, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r1, #0
	strh r1, [r4, #4]
	ldr r2, _0805DF8C @ =0x00002001
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805DF90 @ =Entity0805e67c_OnHit
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0xa
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
_0805DF70: .4byte 0x0000DA6D
_0805DF74: .4byte 0x00000263
_0805DF78: .4byte 0x05000002
_0805DF7C: .4byte 0xFFFF0000
_0805DF80: .4byte 0x0000FFFF
_0805DF84: .4byte 0x00005005
_0805DF88: .4byte Entity0805e67c_OnHurt
_0805DF8C: .4byte 0x00002001
_0805DF90: .4byte Entity0805e67c_OnHit
