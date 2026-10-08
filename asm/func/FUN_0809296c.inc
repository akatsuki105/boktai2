	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _080929F0
	ldr r0, _080929F8 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080929F0
	ldr r1, _080929FC @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08092A00 @ =0x00003AEE
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	ldr r4, _08092A04 @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r1, _08092A08 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r1
	movs r1, #0x24
	orrs r0, r1
	ldr r1, _08092A0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp]
	ldr r1, _08092A10 @ =0x00003FA2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	mov r2, sp
	bl FUN_08092868
	ldr r0, _08092A14 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08092A18 @ =FUN_08092a1c
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
_080929F0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080929F8: .4byte 0x000009EE
_080929FC: .4byte 0x000020AC
_08092A00: .4byte 0x00003AEE
_08092A04: .4byte 0x00000121
_08092A08: .4byte 0xFFFF0000
_08092A0C: .4byte 0x0000FFFF
_08092A10: .4byte 0x00003FA2
_08092A14: .4byte 0x0000010D
_08092A18: .4byte FUN_08092a1c
