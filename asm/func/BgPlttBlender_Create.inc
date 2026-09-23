	push {r4, lr}
	ldr r0, _08019238 @ =0x0300008C
	ldr r0, [r0]
	cmp r0, #0
	bne _08019246
	movs r1, #0xd7
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019244
	ldr r1, _0801923C @ =BgPlttBlender_Update
	ldr r2, _08019240 @ =BgPlttBlender_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl BgPlttBlender_Init
	cmp r0, #0
	bge _08019244
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019246
	.align 2, 0
_08019238: .4byte 0x0300008C
_0801923C: .4byte BgPlttBlender_Update
_08019240: .4byte BgPlttBlender_Destroy
_08019244:
	adds r0, r4, #0
_08019246:
	pop {r4}
	pop {r1}
	bx r1
