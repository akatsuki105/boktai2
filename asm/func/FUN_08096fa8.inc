	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809701C @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08097020 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0809673c
	adds r0, r4, #0
	bl FUN_08096b44
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096bb8
	ldr r2, _08097024 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08096630
	ldr r1, _08097028 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _0809702C @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	bl FUN_080967c0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096d90
	ldr r1, _08097030 @ =FUN_08097034
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809701C: .4byte 0x000014AC
_08097020: .4byte 0x0000144C
_08097024: .4byte 0x00003AE8
_08097028: .4byte 0x00001464
_0809702C: .4byte 0x00003AEB
_08097030: .4byte FUN_08097034
