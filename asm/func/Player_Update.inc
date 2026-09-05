	push {r4, r5, lr}
	adds r4, r0, #0
	bl Player_Update_Helper_0807dde4
	adds r0, r4, #0
	bl FUN_08060bac
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _0807F276
	adds r0, r4, #0
	bl FUN_0807f0bc
	adds r0, r4, #0
	bl Player_UpdateWeaponWear
	adds r0, r4, #0
	bl FUN_0807e388
	ldr r3, _0807F24C @ =0x03002B80
	ldrh r0, [r3]
	cmp r0, #0
	beq _0807F256
	ldr r2, _0807F250 @ =0x03002B78
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0807F254
	subs r0, #1
	strh r0, [r2]
	b _0807F256
	.align 2, 0
_0807F24C: .4byte 0x03002B80
_0807F250: .4byte 0x03002B78
_0807F254:
	strh r1, [r3]
_0807F256:
	adds r0, r4, #0
	bl Player_Update_Helper_0807e968
	cmp r0, #0
	beq _0807F268
	adds r0, r4, #0
	bl FUN_0807e854
	b _0807F2AE
_0807F268:
	adds r0, r4, #0
	bl FUN_0807eca8
	adds r0, r4, #0
	bl dark_django_0807f13c
	b _0807F2AE
_0807F276:
	cmp r0, #2
	bne _0807F2AE
	adds r0, r4, #0
	bl FUN_0806521c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0807F290
	movs r0, #1
	strh r0, [r1]
_0807F290:
	ldr r1, _0807F320 @ =0x00000376
	adds r0, r4, r1
	movs r2, #0
	strh r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	ble _0807F2AE
	strh r2, [r1]
_0807F2AE:
	adds r0, r4, #0
	bl Player_Update_Helper_0807ee58
	ldr r1, _0807F324 @ =0x00000979
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _0807F2C8
	ldr r0, _0807F328 @ =0x00000393
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r5]
_0807F2C8:
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Player_Update_Helper_080639f8
	adds r0, r4, #0
	bl FUN_080612a8
	ldr r0, _0807F32C @ =0x000003EA
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807F2FA
	adds r0, r4, #0
	bl FUN_0807ed04
_0807F2FA:
	ldr r0, [r4, #0x1c]
	cmp r0, #4
	beq _0807F316
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08234660
_0807F316:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807F320: .4byte 0x00000376
_0807F324: .4byte 0x00000979
_0807F328: .4byte 0x00000393
_0807F32C: .4byte 0x000003EA
