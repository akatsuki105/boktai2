	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08247418 @ =0x030026B0
	ldr r0, [r0]
	cmp r0, #0
	bne _08247426
	movs r0, #9
	movs r1, #0x24
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08247424
	ldr r1, _0824741C @ =SSE_Update
	ldr r2, _08247420 @ =SSE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl SSE_Init
	cmp r0, #0
	bge _08247424
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08247426
	.align 2, 0
_08247418: .4byte 0x030026B0
_0824741C: .4byte SSE_Update
_08247420: .4byte SSE_Destroy
_08247424:
	adds r0, r4, #0
_08247426:
	pop {r4, r5}
	pop {r1}
	bx r1
