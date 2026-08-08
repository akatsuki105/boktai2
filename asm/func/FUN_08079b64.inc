	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _08079B7E
	cmp r0, #2
	beq _08079C28
	b _08079C4A
_08079B7E:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08079B98
	ldr r0, _08079C18 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08079C1C @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl FUN_080667b0
_08079B98:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08079BAE
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_08079BAE:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_0807998c
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _08079C20 @ =0x085ABE1C
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08079BEC
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08079BEC:
	adds r0, r5, #0
	bl FUN_08079a64
	ldr r1, _08079C24 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079C04
	adds r0, r5, #0
	bl FUN_08066df8
_08079C04:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_08065dac
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079C4A
	.align 2, 0
_08079C18: .4byte 0x030046A0
_08079C1C: .4byte 0x00000942
_08079C20: .4byte 0x085ABE1C
_08079C24: .4byte 0x000003CE
_08079C28:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08079a64
	adds r0, r5, #0
	bl FUN_080726ec
_08079C4A:
	pop {r4, r5}
	pop {r0}
	bx r0
