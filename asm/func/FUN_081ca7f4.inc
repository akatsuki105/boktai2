	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081CA80C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA810
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA812
	.align 2, 0
_081CA80C: .4byte 0x0000046C
_081CA810:
	movs r0, #0
_081CA812:
	cmp r0, #0
	beq _081CA890
	ldr r4, _081CA8A4 @ =FUN_081c87c8
	movs r3, #0xa
	ldr r2, _081CA8A8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CA8AC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	bl Enemy_RunScript
	ldr r2, _081CA8B0 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081CA874
	movs r0, #4
	ldr r1, _081CA8B4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081CA874:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_081CA890:
	ldr r1, _081CA8AC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CA8B8
	adds r0, r5, #0
	bl FUN_081c6048
	b _081CA8C2
	.align 2, 0
_081CA8A4: .4byte FUN_081c87c8
_081CA8A8: .4byte 0x0000046D
_081CA8AC: .4byte 0x0000046B
_081CA8B0: .4byte 0x000001DF
_081CA8B4: .4byte 0x00000222
_081CA8B8:
	ldr r2, _081CA8C8 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CA8C2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CA8C8: .4byte 0x00000484
