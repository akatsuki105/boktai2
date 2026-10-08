	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093CAC
	ldr r0, _08093CB4 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093CAC
	ldr r0, _08093CB8 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08093CBC @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08093CC0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r1, _08093CC4 @ =FUN_08093cc8
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
_08093CAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093CB4: .4byte 0x000009EE
_08093CB8: .4byte 0x0000010D
_08093CBC: .4byte 0x000020AC
_08093CC0: .4byte 0x00003AEE
_08093CC4: .4byte FUN_08093cc8
