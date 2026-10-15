	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08009050 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _0800905E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800905C
	ldr r1, _08009054 @ =Entity5DA5_Update
	ldr r2, _08009058 @ =Entity5DA5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity5DA5_Init
	cmp r0, #0
	bge _0800905C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800905E
	.align 2, 0
_08009050: .4byte 0x03000038
_08009054: .4byte Entity5DA5_Update
_08009058: .4byte Entity5DA5_Destroy
_0800905C:
	adds r0, r4, #0
_0800905E:
	pop {r4, r5}
	pop {r1}
	bx r1
