	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805D394 @ =0x000016A8
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D3A0
	ldr r1, _0805D398 @ =Entity0805d364_Update
	ldr r2, _0805D39C @ =Entity0805d364_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805d364_Init
	cmp r0, #0
	bge _0805D3A0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D3A2
	.align 2, 0
_0805D394: .4byte 0x000016A8
_0805D398: .4byte Entity0805d364_Update
_0805D39C: .4byte Entity0805d364_Destroy
_0805D3A0:
	adds r0, r4, #0
_0805D3A2:
	pop {r4, r5}
	pop {r1}
	bx r1
