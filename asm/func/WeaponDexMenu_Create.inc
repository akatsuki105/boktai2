	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08211090 @ =0x00000DA4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821109C
	ldr r1, _08211094 @ =WeaponDexMenu_Update
	ldr r2, _08211098 @ =WeaponDexMenu_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl WeaponDexMenu_Init
	cmp r0, #0
	bge _0821109C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821109E
	.align 2, 0
_08211090: .4byte 0x00000DA4
_08211094: .4byte WeaponDexMenu_Update
_08211098: .4byte WeaponDexMenu_Destroy
_0821109C:
	adds r0, r4, #0
_0821109E:
	pop {r4, r5}
	pop {r1}
	bx r1
