	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl Salamander_StepPaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AC7EE
	ldr r0, _081AC7D0 @ =0x00000C3C
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081AC7D8
	movs r1, #0xd3
	lsls r1, r1, #1
	ldr r2, _081AC7D4 @ =0x000001A5
	b _081AC7DE
	.align 2, 0
_081AC7D0: .4byte 0x00000C3C
_081AC7D4: .4byte 0x000001A5
_081AC7D8:
	ldr r1, _081AC7F4 @ =0x000001A5
	movs r2, #0xd3
	lsls r2, r2, #1
_081AC7DE:
	adds r0, r5, #0
	movs r3, #0x14
	bl Salamander_StartPaletteFade
	ldrb r0, [r4]
	movs r1, #1
	eors r0, r1
	strb r0, [r4]
_081AC7EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AC7F4: .4byte 0x000001A5
