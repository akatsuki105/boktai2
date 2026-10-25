	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r3, #0
	ldr r7, _0809EC90 @ =0x00000AAC
	add r7, r8
_0809EC6E:
	ldr r1, _0809EC94 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r6, [r0]
	adds r5, r3, #1
	cmp r6, #0
	beq _0809ED3E
	ldr r0, [r6, #0x1c]
	cmp r0, #1
	bne _0809ED3E
	movs r0, #0x20
	ldr r1, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809EC98
	movs r1, #2
	b _0809ECA0
	.align 2, 0
_0809EC90: .4byte 0x00000AAC
_0809EC94: .4byte 0x03002BE0
_0809EC98:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809ECA0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809ECC8
	cmp r1, #2
	bne _0809ECBA
	lsls r2, r3, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x28
	b _0809ED0E
_0809ECBA:
	lsls r2, r3, #1
	cmp r1, #0
	bne _0809ED10
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #5
	b _0809ED0E
_0809ECC8:
	cmp r1, #2
	bne _0809ECEA
	ldr r0, _0809ECD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ECDC
	movs r0, #0
	b _0809ECE2
	.align 2, 0
_0809ECD8: .4byte 0x03002C68
_0809ECDC:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ECE2:
	lsls r2, r3, #1
	adds r1, r7, r2
	lsls r0, r0, #3
	b _0809ED0A
_0809ECEA:
	lsls r2, r3, #1
	cmp r1, #1
	bne _0809ED10
	ldr r0, _0809ECFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED00
	movs r0, #0
	b _0809ED06
	.align 2, 0
_0809ECFC: .4byte 0x03002C68
_0809ED00:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ED06:
	lsls r2, r3, #1
	adds r1, r7, r2
_0809ED0A:
	ldrh r4, [r1]
	adds r0, r0, r4
_0809ED0E:
	strh r0, [r1]
_0809ED10:
	movs r4, #0
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r3, #1
	cmp r0, #0x77
	bls _0809ED32
	ldr r3, _0809ED50 @ =0x00000AAC
	add r3, r8
_0809ED20:
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #0x78
	strh r0, [r1]
	adds r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809ED20
_0809ED32:
	cmp r4, #0
	ble _0809ED3E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0807aa30
_0809ED3E:
	adds r3, r5, #0
	cmp r3, #3
	ble _0809EC6E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809ED50: .4byte 0x00000AAC
