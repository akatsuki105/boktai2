	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08090700 @ =0x00004039
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809070C
	ldr r1, [r4, #0x28]
	ldr r2, _08090704 @ =0x00004038
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r3, _08090708 @ =0x0000402C
	adds r2, r4, r3
	ldr r2, [r2]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r0, #1
	bl Video_SetBGLayer
	adds r0, r4, #0
	bl FUN_0808ff84
	adds r0, r4, #0
	bl FUN_08090148
	b _0809071E
	.align 2, 0
_08090700: .4byte 0x00004039
_08090704: .4byte 0x00004038
_08090708: .4byte 0x0000402C
_0809070C:
	adds r0, r4, #0
	bl FUN_08090698
	adds r0, r4, #0
	bl FUN_08090004
	adds r0, r4, #0
	bl FUN_08090148
_0809071E:
	pop {r4}
	pop {r0}
	bx r0
