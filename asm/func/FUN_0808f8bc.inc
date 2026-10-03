	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F8F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808F8FC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F914
	movs r0, #5
	bl TextBox_ShowLine
	ldr r1, _0808F900 @ =0x00004028
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808F904
	movs r1, #0
	bl VM_ExecByID
	b _0808F90C
	.align 2, 0
_0808F8F8: .4byte 0x000034E4
_0808F8FC: .4byte 0x000009EC
_0808F900: .4byte 0x00004028
_0808F904:
	movs r0, #0
	movs r1, #3
	bl TextBox_SetVarValue
_0808F90C:
	ldr r1, _0808F91C @ =FUN_0808f920
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F91C: .4byte FUN_0808f920
