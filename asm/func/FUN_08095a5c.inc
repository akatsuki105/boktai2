	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08095AD0 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808de30
	adds r0, r4, #0
	bl FUN_0809536c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080954a8
	ldr r1, _08095AD4 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _08095AD8 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08094a94
	ldr r1, _08095ADC @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08095AE0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	bl weapon_08094f88
	adds r0, r4, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _08095AE4 @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095AD0: .4byte 0x000014AC
_08095AD4: .4byte 0x0000144C
_08095AD8: .4byte 0x00003AE8
_08095ADC: .4byte 0x00001464
_08095AE0: .4byte 0x00003AEB
_08095AE4: .4byte FUN_08095ae8
