	push {r4, lr}
	ldr r1, _0821386C @ =0x0000042C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08213878
	ldr r1, _08213870 @ =Intro_Update
	ldr r2, _08213874 @ =Intro_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Intro_Init
	cmp r0, #0
	bge _08213878
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821387A
	.align 2, 0
_0821386C: .4byte 0x0000042C
_08213870: .4byte Intro_Update
_08213874: .4byte Intro_Destroy
_08213878:
	adds r0, r4, #0
_0821387A:
	pop {r4}
	pop {r1}
	bx r1
