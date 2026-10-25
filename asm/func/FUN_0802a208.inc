	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r6, r4, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_Add
	str r5, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0x4e
	movs r3, #2
	bl MainSprite_SetAnim
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0802A2C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802A2C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0802A2C8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x70
	ldr r2, _0802A2CC @ =0x00000B01
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0802A2D0 @ =0x00000B02
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	adds r2, #2
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802A2D4 @ =0x00000B04
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _0802A2D8 @ =0x00000B06
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0802A2DC @ =0x00000B08
	adds r5, r4, r0
	movs r1, #0xac
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r5, #0
	bl ParticleShadow_Hide
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A2C0: .4byte 0x030046B8
_0802A2C4: .4byte 0x000003FF
_0802A2C8: .4byte 0x0203B400
_0802A2CC: .4byte 0x00000B01
_0802A2D0: .4byte 0x00000B02
_0802A2D4: .4byte 0x00000B04
_0802A2D8: .4byte 0x00000B06
_0802A2DC: .4byte 0x00000B08
