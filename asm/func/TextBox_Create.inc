	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0804885C @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	bne _08048868
	movs r1, #0xbc
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08048868
	ldr r1, _08048860 @ =TextBox_Update
	ldr r2, _08048864 @ =TextBox_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl TextBox_Init
	cmp r0, #0
	bge _08048868
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804886A
	.align 2, 0
_0804885C: .4byte 0x030000C4
_08048860: .4byte TextBox_Update
_08048864: .4byte TextBox_Destroy
_08048868:
	adds r0, r4, #0
_0804886A:
	pop {r4, r5}
	pop {r1}
	bx r1
