	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x2c]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #1
	bne _08040FF0
	movs r0, #0x91
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r0, r4, #0
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Show
	b _0804102C
_08040FF0:
	cmp r2, #2
	bne _0804102C
	movs r6, #0x91
	lsls r6, r6, #2
	adds r4, r4, r6
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [sp, #8]
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r0, #4
	str r0, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	adds r0, r4, #0
	adds r2, r3, #0
	bl AuxShadow_Init
	ldr r1, _08041038 @ =0x00001C1B
	adds r0, r4, #0
	adds r2, r5, #0
	bl AuxShadow_SetSprite
	adds r0, r4, #0
	bl AuxShadow_Show
_0804102C:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08041038: .4byte 0x00001C1B
