	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08096154 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08096130
	ldr r0, _08096158 @ =0x0000038A
	bl PlaySound_082406e0
_08096130:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08096164
	ldr r1, _0809615C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08096160 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809618E
	.align 2, 0
_08096154: .4byte 0x000009EE
_08096158: .4byte 0x0000038A
_0809615C: .4byte 0x000020C4
_08096160: .4byte 0x00003B68
_08096164:
	ldr r0, _08096194 @ =0x00000111
	bl PlaySound_082406e0
	ldr r0, _08096198 @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0809619C @ =0x00003AEE
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _080961A0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	subs r1, #0x10
	bl FUN_08242f44
	adds r0, r4, #0
	bl FUN_08095a5c
_0809618E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096194: .4byte 0x00000111
_08096198: .4byte 0x000020AC
_0809619C: .4byte 0x00003AEE
_080961A0: .4byte 0x00003AEB
