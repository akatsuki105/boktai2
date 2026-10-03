	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08098624 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08098600
	ldr r0, _08098628 @ =0x0000038A
	bl PlaySound_082406e0
_08098600:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08098634
	ldr r1, _0809862C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08098630 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809866A
	.align 2, 0
_08098624: .4byte 0x000009EE
_08098628: .4byte 0x0000038A
_0809862C: .4byte 0x000020C4
_08098630: .4byte 0x00003B68
_08098634:
	ldr r0, _08098670 @ =0x00000111
	bl PlaySound_082406e0
	ldr r3, _08098674 @ =0x000020AC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08098678 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x10
	ldr r3, _0809867C @ =0x00003AEE
	adds r2, r4, r3
	ldr r3, _08098680 @ =0x00003FF0
	adds r1, r4, r3
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl RegisterMagic
	adds r0, r4, #0
	bl FUN_0809820c
_0809866A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098670: .4byte 0x00000111
_08098674: .4byte 0x000020AC
_08098678: .4byte 0x00003AEB
_0809867C: .4byte 0x00003AEE
_08098680: .4byte 0x00003FF0
