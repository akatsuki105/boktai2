	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08096254 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08096220
	ldr r0, _08096258 @ =0x0000038A
	bl PlaySound_082406e0
_08096220:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809626C
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _0809625C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08096260 @ =0x00003B68
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _08096264 @ =0x00002124
	adds r0, r5, r1
	ldr r2, _08096268 @ =0x00003B70
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _08096298
	.align 2, 0
_08096254: .4byte 0x000009EE
_08096258: .4byte 0x0000038A
_0809625C: .4byte 0x000020C4
_08096260: .4byte 0x00003B68
_08096264: .4byte 0x00002124
_08096268: .4byte 0x00003B70
_0809626C:
	ldr r0, _080962A0 @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080962A4 @ =0x0000210C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080962A8 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _080962AC @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl SwapWeaponSlot
	adds r0, r5, #0
	bl FUN_08095a5c
_08096298:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080962A0: .4byte 0x000020AC
_080962A4: .4byte 0x0000210C
_080962A8: .4byte 0x00003AEE
_080962AC: .4byte 0x00003AEB
