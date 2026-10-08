	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809763C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08097618
	ldr r0, _08097640 @ =0x0000038A
	bl PlaySound_082406e0
_08097618:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809764C
	ldr r1, _08097644 @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08097648 @ =0x00003B68
	adds r1, r5, r2
	ldrh r3, [r4]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _08097662
	.align 2, 0
_0809763C: .4byte 0x000009EE
_08097640: .4byte 0x0000038A
_08097644: .4byte 0x000020C4
_08097648: .4byte 0x00003B68
_0809764C:
	ldr r0, _08097668 @ =0x000020AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0809766C @ =FUN_08097670
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
_08097662:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097668: .4byte 0x000020AC
_0809766C: .4byte FUN_08097670
