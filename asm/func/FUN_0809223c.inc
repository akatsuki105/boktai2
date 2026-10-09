	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0
	mov r8, r0
	ldr r1, _08092278 @ =0x00003F9C
	adds r1, r1, r6
	mov sb, r1
	ldr r0, _0809227C @ =0x000015C4
	adds r5, r6, r0
	movs r7, #0xcc
	lsls r7, r7, #3
_08092258:
	mov r1, sb
	ldrb r0, [r1]
	mov r1, r8
	bl GetItemID
	adds r4, r0, #0
	cmp r4, #0
	bge _08092284
	ldr r1, _08092280 @ =0x00000F6C
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080922E0
	.align 2, 0
_08092278: .4byte 0x00003F9C
_0809227C: .4byte 0x000015C4
_08092280: .4byte 0x00000F6C
_08092284:
	ldr r0, _080922C4 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r7
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080922D8
	adds r0, r4, #0
	bl FUN_08091cb8
	cmp r0, #0
	beq _080922CC
	adds r0, r5, #0
	ldr r1, _080922C8 @ =0x000002DF
	bl MainSprite_SetPltt
	b _080922E0
	.align 2, 0
_080922C4: .4byte 0x00000F6C
_080922C8: .4byte 0x000002DF
_080922CC:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
	b _080922E0
_080922D8:
	adds r0, r5, #0
	ldr r1, _080922FC @ =0x000002DF
	bl MainSprite_SetPltt
_080922E0:
	adds r5, #0x60
	adds r7, #0x60
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #0xf
	ble _08092258
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080922FC: .4byte 0x000002DF
