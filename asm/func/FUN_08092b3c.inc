	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08092B98
	ldr r0, _08092BA0 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08092B98
	ldr r1, _08092BA4 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08092BA8 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	ldr r4, _08092BAC @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r0, _08092BB0 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08092BB4 @ =FUN_08092bb8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08092B98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092BA0: .4byte 0x000009EE
_08092BA4: .4byte 0x000020AC
_08092BA8: .4byte 0x00003AEE
_08092BAC: .4byte 0x00000121
_08092BB0: .4byte 0x0000010D
_08092BB4: .4byte FUN_08092bb8
