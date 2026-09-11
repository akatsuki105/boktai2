	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08012C60 @ =0x00000D08
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08012C6C
	ldr r1, _08012C64 @ =EntityE534_Update
	ldr r2, _08012C68 @ =EntityE534_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityE534_Init
	cmp r0, #0
	bge _08012C6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08012C6E
	.align 2, 0
_08012C60: .4byte 0x00000D08
_08012C64: .4byte EntityE534_Update
_08012C68: .4byte EntityE534_Destroy
_08012C6C:
	adds r0, r4, #0
_08012C6E:
	pop {r4, r5}
	pop {r1}
	bx r1
