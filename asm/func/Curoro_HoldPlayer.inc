	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0813AAE8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AAEC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813AAEE
	.align 2, 0
_0813AAE8: .4byte 0x0000046D
_0813AAEC:
	movs r0, #0
_0813AAEE:
	cmp r0, #0
	beq _0813AB0C
	ldr r0, _0813AB5C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r4, _0813AB60 @ =0x0000066B
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0813AB64 @ =0x0000065E
	adds r0, r6, r1
	strh r2, [r0]
_0813AB0C:
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080efe38
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r3, _0813AB68 @ =0x0000065C
	adds r1, r6, r3
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0813ABB2
	movs r4, #0x90
	lsls r4, r4, #3
	adds r2, r5, r4
	ldrh r3, [r2]
	cmp r3, #0
	bne _0813AB6C
	ldr r0, _0813AB5C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r4, #0x8b
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	str r3, [sp]
	adds r4, #0x10
	adds r3, r5, r4
	ldr r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Player_TakeInstantHit
	b _0813ABB2
	.align 2, 0
_0813AB5C: .4byte 0x03002BE0
_0813AB60: .4byte 0x0000066B
_0813AB64: .4byte 0x0000065E
_0813AB68: .4byte 0x0000065C
_0813AB6C:
	ldr r0, _0813AB98 @ =0x0000065E
	adds r1, r6, r0
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bls _0813ABB2
	ldrh r0, [r2]
	cmp r0, #1
	bne _0813ABA0
	ldr r0, _0813AB9C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl Player_StartFormEffect
	b _0813ABAA
	.align 2, 0
_0813AB98: .4byte 0x0000065E
_0813AB9C: .4byte 0x03002BE0
_0813ABA0:
	ldr r0, _0813ABD0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #2
	bl Player_StartFormEffect
_0813ABAA:
	ldr r0, _0813ABD4 @ =0x0000065E
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
_0813ABB2:
	ldr r1, _0813ABD8 @ =0x0000066B
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r0, _0813ABD0 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0813ABE0
	ldr r4, _0813ABDC @ =0xFFFFFF00
	adds r0, r2, r4
	subs r4, r1, r0
	b _0813ABE2
	.align 2, 0
_0813ABD0: .4byte 0x03002BE0
_0813ABD4: .4byte 0x0000065E
_0813ABD8: .4byte 0x0000066B
_0813ABDC: .4byte 0xFFFFFF00
_0813ABE0:
	subs r4, r1, r2
_0813ABE2:
	ldr r0, _0813AC28 @ =0x0000066A
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, r4
	beq _0813AC06
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0813AC04
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813AC04:
	strb r4, [r7]
_0813AC06:
	ldr r2, _0813AC28 @ =0x0000066A
	adds r0, r6, r2
	ldr r3, _0813AC2C @ =0x0000065D
	adds r1, r6, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _0813AC1E
	ldr r4, _0813AC30 @ =0x0000046B
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_0813AC1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813AC28: .4byte 0x0000066A
_0813AC2C: .4byte 0x0000065D
_0813AC30: .4byte 0x0000046B
