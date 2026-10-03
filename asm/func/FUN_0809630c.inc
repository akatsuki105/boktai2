	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08096344 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08096320
	ldr r0, _08096348 @ =0x0000038A
	bl PlaySound_082406e0
_08096320:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08096354
	ldr r1, _0809634C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08096350 @ =0x00003B68
	adds r1, r5, r2
	ldrh r3, [r4]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809636A
	.align 2, 0
_08096344: .4byte 0x000009EE
_08096348: .4byte 0x0000038A
_0809634C: .4byte 0x000020C4
_08096350: .4byte 0x00003B68
_08096354:
	ldr r0, _08096370 @ =0x000020AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08096374 @ =FUN_08096378
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_0809636A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096370: .4byte 0x000020AC
_08096374: .4byte FUN_08096378
