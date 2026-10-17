	push {r4, lr}
	movs r1, #0xa9
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DAE6C
	ldr r1, _081DAE64 @ =Entity7999_Update
	ldr r2, _081DAE68 @ =Entity7999_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity7999_Init
	cmp r0, #0
	bge _081DAE6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DAE6E
	.align 2, 0
_081DAE64: .4byte Entity7999_Update
_081DAE68: .4byte Entity7999_Destroy
_081DAE6C:
	adds r0, r4, #0
_081DAE6E:
	pop {r4}
	pop {r1}
	bx r1
