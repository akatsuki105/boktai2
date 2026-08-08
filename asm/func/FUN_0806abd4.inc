	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _0806ABF8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806ABEC
	b _0806ADC0
_0806ABEC:
	lsls r0, r0, #2
	ldr r1, _0806ABFC @ =_0806AC00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806ABF8: .4byte 0x0000037D
_0806ABFC: .4byte _0806AC00
_0806AC00: @ jump table
	.4byte _0806AC18 @ case 0
	.4byte _0806AC5C @ case 1
	.4byte _0806ACA8 @ case 2
	.4byte _0806AD0C @ case 3
	.4byte _0806AD70 @ case 4
	.4byte _0806ADB8 @ case 5
_0806AC18:
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
	ldr r0, _0806AC54 @ =0x000001AD
	bl PlaySound_082406e0
	adds r1, r5, #0
	adds r1, #0xef
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #1
	bl FUN_08060b84
	ldr r1, _0806AC58 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	b _0806ADC0
	.align 2, 0
_0806AC54: .4byte 0x000001AD
_0806AC58: .4byte 0x000003F6
_0806AC5C:
	ldr r0, _0806AC9C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806AC70
	b _0806ADC0
_0806AC70:
	movs r0, #4
	str r0, [sp]
	ldr r0, _0806ACA0 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r0, _0806ACA4 @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #2
	bl FUN_08060b84
	b _0806ADC0
	.align 2, 0
_0806AC9C: .4byte 0x0000037E
_0806ACA0: .4byte 0x00001FFF
_0806ACA4: .4byte 0x000003F6
_0806ACA8:
	ldr r1, _0806ACC8 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #9
	bne _0806ACD4
	subs r1, #0x26
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806ACCC
	movs r0, #0xbb
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806ACD4
	.align 2, 0
_0806ACC8: .4byte 0x0000037E
_0806ACCC:
	movs r0, #0xc1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806ACD4:
	ldr r0, _0806AD00 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _0806ADC0
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #3
	bl FUN_08060b84
	ldr r1, _0806AD04 @ =0x000003F6
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0806AD08 @ =0x000001AF
	bl PlaySound_082406e0
	b _0806ADC0
	.align 2, 0
_0806AD00: .4byte 0x0000037E
_0806AD04: .4byte 0x000003F6
_0806AD08: .4byte 0x000001AF
_0806AD0C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806AD58 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806AD5C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _0806AD60
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #4
	bl FUN_08060b84
	b _0806ADC0
	.align 2, 0
_0806AD58: .4byte 0x000003F6
_0806AD5C: .4byte 0x0000037E
_0806AD60:
	adds r0, r5, #0
	adds r0, #0xe8
	ldrh r1, [r1]
	movs r2, #0xa
	movs r3, #0x14
	bl FUN_082375c8
	b _0806ADC0
_0806AD70:
	ldr r0, _0806ADAC @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806ADB0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0806ADC0
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #5
	bl FUN_08060b84
	ldr r0, _0806ADB4 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806ADC0
	.align 2, 0
_0806ADAC: .4byte 0x000003F6
_0806ADB0: .4byte 0x0000037E
_0806ADB4: .4byte 0x030047A4
_0806ADB8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
_0806ADC0:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
