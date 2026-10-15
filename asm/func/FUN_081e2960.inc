	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
_081E2966:
	cmp r3, #0xf
	bls _081E296C
	b _081E2AF8
_081E296C:
	lsls r0, r3, #2
	ldr r1, _081E2978 @ =_081E297C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2978: .4byte _081E297C
_081E297C: @ jump table
	.4byte _081E29BC @ case 0
	.4byte _081E29D2 @ case 1
	.4byte _081E29E8 @ case 2
	.4byte _081E29FE @ case 3
	.4byte _081E2A14 @ case 4
	.4byte _081E2A2A @ case 5
	.4byte _081E2A40 @ case 6
	.4byte _081E2A56 @ case 7
	.4byte _081E2A6C @ case 8
	.4byte _081E2A7C @ case 9
	.4byte _081E2A8C @ case 10
	.4byte _081E2A9C @ case 11
	.4byte _081E2AB2 @ case 12
	.4byte _081E2AC2 @ case 13
	.4byte _081E2AD2 @ case 14
	.4byte _081E2AE2 @ case 15
_081E29BC:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29D2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x50
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29E8:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29FE:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A14:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A2A:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A40:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A56:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A6C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	b _081E2AF0
_081E2A7C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x38
	b _081E2AF0
_081E2A8C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	b _081E2AF0
_081E2A9C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x48
	movs r2, #0x50
	strh r2, [r1]
	adds r0, #0x4a
	strh r2, [r0]
	b _081E2AF8
_081E2AB2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	b _081E2AF0
_081E2AC2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xb8
	b _081E2AF0
_081E2AD2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	b _081E2AF0
_081E2AE2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
_081E2AF0:
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x50
_081E2AF6:
	strh r1, [r0]
_081E2AF8:
	adds r3, #1
	cmp r3, #0xf
	bgt _081E2B00
	b _081E2966
_081E2B00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
