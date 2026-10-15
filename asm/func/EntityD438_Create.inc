	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08055B44 @ =0x03000124
	ldr r0, [r0]
	cmp r0, #0
	bne _08055B52
	movs r0, #8
	movs r1, #0x78
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08055B50
	ldr r1, _08055B48 @ =EntityD438_Update
	ldr r2, _08055B4C @ =EntityD438_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityD438_Init
	cmp r0, #0
	bge _08055B50
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08055B52
	.align 2, 0
_08055B44: .4byte 0x03000124
_08055B48: .4byte EntityD438_Update
_08055B4C: .4byte EntityD438_Destroy
_08055B50:
	adds r0, r4, #0
_08055B52:
	pop {r4, r5}
	pop {r1}
	bx r1
