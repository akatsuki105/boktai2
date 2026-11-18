	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r2, _0819EA68 @ =0x00000ECC
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819EA40
	ldr r1, [r3, #0x44]
	movs r2, #0
	movs r0, #0xfa
	strh r0, [r1, #0x32]
	ldr r1, [r3, #0x44]
	ldr r6, _0819EA6C @ =0x0000093C
	adds r0, r4, r6
	str r0, [r1, #0x38]
	ldr r1, _0819EA70 @ =0x00000ECB
	adds r0, r4, r1
	strb r2, [r0]
	ldr r6, _0819EA74 @ =0x00000ECA
	adds r0, r4, r6
	strb r2, [r0]
	strb r2, [r5]
_0819EA40:
	ldr r0, _0819EA78 @ =0x00000ECD
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819EA80
	ldr r0, [r3, #0x44]
	adds r0, #0x2c
	ldr r2, _0819EA7C @ =0x0000047A
	adds r1, r3, r2
	ldrh r1, [r1]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r2, [r2]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	movs r0, #0
	strb r0, [r5]
	b _0819EB24
	.align 2, 0
_0819EA68: .4byte 0x00000ECC
_0819EA6C: .4byte 0x0000093C
_0819EA70: .4byte 0x00000ECB
_0819EA74: .4byte 0x00000ECA
_0819EA78: .4byte 0x00000ECD
_0819EA7C: .4byte 0x0000047A
_0819EA80:
	ldr r0, [r3, #0x44]
	ldrh r0, [r0, #0x32]
	cmp r0, #0xfa
	bne _0819EB24
	ldr r6, _0819EA9C @ =0x00000ECB
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #6
	bhi _0819EAEC
	lsls r0, r0, #2
	ldr r1, _0819EAA0 @ =_0819EAA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819EA9C: .4byte 0x00000ECB
_0819EAA0: .4byte _0819EAA4
_0819EAA4: @ jump table
	.4byte _0819EAC0 @ case 0
	.4byte _0819EACC @ case 1
	.4byte _0819EAD8 @ case 2
	.4byte _0819EAE4 @ case 3
	.4byte _0819EAD8 @ case 4
	.4byte _0819EACC @ case 5
	.4byte _0819EAC0 @ case 6
_0819EAC0:
	ldr r0, _0819EAC8 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0
	b _0819EAEA
	.align 2, 0
_0819EAC8: .4byte 0x0000093E
_0819EACC:
	ldr r2, _0819EAD4 @ =0x0000093E
	adds r1, r4, r2
	movs r0, #0x10
	b _0819EAEA
	.align 2, 0
_0819EAD4: .4byte 0x0000093E
_0819EAD8:
	ldr r6, _0819EAE0 @ =0x0000093E
	adds r1, r4, r6
	movs r0, #0x18
	b _0819EAEA
	.align 2, 0
_0819EAE0: .4byte 0x0000093E
_0819EAE4:
	ldr r0, _0819EB0C @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x1f
_0819EAEA:
	strh r0, [r1]
_0819EAEC:
	ldr r2, _0819EB10 @ =0x00000ECA
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0819EB24
	ldr r6, _0819EB14 @ =0x00000ECB
	adds r1, r4, r6
	ldrb r0, [r1]
	cmp r0, #5
	bls _0819EB18
	movs r0, #0
	b _0819EB1A
	.align 2, 0
_0819EB0C: .4byte 0x0000093E
_0819EB10: .4byte 0x00000ECA
_0819EB14: .4byte 0x00000ECB
_0819EB18:
	adds r0, #1
_0819EB1A:
	strb r0, [r1]
	ldr r0, _0819EB2C @ =0x00000ECA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0819EB24:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819EB2C: .4byte 0x00000ECA
