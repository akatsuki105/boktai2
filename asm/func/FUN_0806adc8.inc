	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _0806ADEC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806ADE0
	b _0806AF68
_0806ADE0:
	lsls r0, r0, #2
	ldr r1, _0806ADF0 @ =_0806ADF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806ADEC: .4byte 0x0000037D
_0806ADF0: .4byte _0806ADF4
_0806ADF4: @ jump table
	.4byte _0806AE0C @ case 0
	.4byte _0806AE50 @ case 1
	.4byte _0806AE84 @ case 2
	.4byte _0806AEDC @ case 3
	.4byte _0806AF24 @ case 4
	.4byte _0806AF60 @ case 5
_0806AE0C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806AE48 @ =0x000001AD
	bl PlaySound_082406e0
	adds r1, r5, #0
	adds r1, #0xef
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_08060b84
	ldr r1, _0806AE4C @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	b _0806AF68
	.align 2, 0
_0806AE48: .4byte 0x000001AD
_0806AE4C: .4byte 0x000003F6
_0806AE50:
	ldr r0, _0806AE80 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806AE64
	b _0806AF68
_0806AE64:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #2
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AE80: .4byte 0x0000037E
_0806AE84:
	ldr r0, _0806AED0 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806AED4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0806AF68
	adds r0, r5, #0
	adds r0, #0x2c
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_08016110
	ldr r0, _0806AED8 @ =0x00000145
	bl PlaySound_082406e0
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #3
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AED0: .4byte 0x000003F6
_0806AED4: .4byte 0x0000037E
_0806AED8: .4byte 0x00000145
_0806AEDC:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806AF1C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806AF68
	movs r0, #4
	str r0, [sp]
	ldr r0, _0806AF20 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #4
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AF1C: .4byte 0x0000037E
_0806AF20: .4byte 0x00001FFF
_0806AF24:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806AF58 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806AF68
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #5
	bl FUN_08060b84
	ldr r0, _0806AF5C @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806AF68
	.align 2, 0
_0806AF58: .4byte 0x0000037E
_0806AF5C: .4byte 0x030047A4
_0806AF60:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
_0806AF68:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
